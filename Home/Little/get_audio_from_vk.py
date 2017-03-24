/*
    WARNING!
    This code does not work anymore, because VK closed their API for audio.since December 2016
*/

import os
import requests
from selenium import webdriver
import json
from datetime import datetime

logsize = os.path.getsize('log.txt')


print(logsize / 1024 / 1024)
# exit()


if (logsize / 1024 / 1024 > 2):
    open('log.txt', 'w').close()

logger = open('log.txt', 'a')


def log(text):
    logger.write('[' + str(datetime.now()) + '] ' + text + '\n')


log('Downloading started')

tokensaver = open('token.token', 'r')

current = tokensaver.readline()
date = tokensaver.readline()
tokensaver.close()

if (current == ''):
    tokensaver = open('token.token', 'w')
    print("DRIVER ADKRYVAJECCA")
    log('Requesting new token')

    driver = webdriver.Firefox()
    driver.get("https://oauth.vk.com/authorize?"
               "client_id=5591707&scope=4104"
               "&redirect_uri=http://api.vk.com/blank.html"
               "&display=page&response_type=token")

    user = "email"  # Here enter your email
    password = "pass"  # Here'll be the pass

    user_input = driver.find_element_by_name("email")
    user_input.send_keys(user)
    password_input = driver.find_element_by_name("pass")
    password_input.send_keys(password)

    submit = driver.find_element_by_id("install_allow")
    submit.click()

    current = driver.current_url
    driver.close()
    tokensaver.write(str(current))
    log('get token - SUCCESS')

access_list = (current.split("#"))[1].split("&")
access_token = (access_list[0].split("="))[1]
expires_in = (access_list[1].split("="))[1]
user_id = (access_list[2].split("="))[1]

print("Connecting")
log('Connecting to VK API')

url = "https://api.vk.com/method/" \
      "audio.get?uid=" + user_id +\
      "&access_token=" + access_token

artists_list = []
titles_list = []
links_list = []

number = 0

page = requests.get(url)
html = page.text

my_dict = json.loads(html)

for i in my_dict['response']:
    artists_list.append(i['artist'].replace("/", " "))
    titles_list.append(i['title'].replace("/", " "))
    links_list.append(i['url'])
    number += 1

log('List of audio has been successfully recieved')

path = "downloads"

log('Downloading audio to ' + path)

if not os.path.exists(path):
    os.makedirs(path)

print("Need to download: ", number)
log('Need to download: ' + str(number))


for i in range(0, number):

    new_filename = path + "/" + artists_list[i] +
                   " - " + titles_list[i] + ".mp3"
    print("Downloading: ", new_filename, i)
    log('Checking ' + new_filename)

    if not os.path.exists(new_filename):
        log('Downloading ' + new_filename)
        print("TIME: ", str(datetime.now()))
        with open(new_filename, "wb") as out:
            response = requests.get(links_list[i].split("?")[0])
            out.write(response.content)

page = requests.get("https://api.vk.com/method/" +
             "messages.send?user_id=" + user_id +
             "&message=[" + str(datetime.now()) + "] Усе песьні смампаваныя" +
             "&access_token=" + access_token + "&v=5.53")

print("Download complete.")
log('Download complete\n\n***\n\n')
logger.close()
