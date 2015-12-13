var a:array[1..1000000]of integer;
    i,n,x,l:longint;
    f1,f2:text;
begin
 assign(f1,'input.txt');
 assign(f2,'output.txt');
 reset(f1);
 readln(f1,n);
 for i:=1 to n do read(f1,a[i]);
 for i:=1 to n do l:=l+a[i];
 rewrite(f2);
 if l mod n<>0 then begin writeln(f2,'NO'); writeln(f2,n-(l mod n)); end
               else begin writeln(f2,'YES'); for i:=1 to n do if a[i]<l div n then x:=x+(l div n)-a[i]; writeln(f2,x); end;
 close(f1);
 close(f2);
end.

