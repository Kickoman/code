program a3;
var c, a, max, resp ,n, m, i, i1, i2:integer;
map:array[1..2000] of array[1..2000] of boolean;

function clear(a, x, y:integer):boolean;
var i, i1:integer;
begin
clear:=true;
for i:=x to x+a-1 do for i1:=y to y+a-1 do
        begin
        if map[i][i1]=true then clear:=false;
        end;
end;

begin
assign(Input, 'input.txt');
reset(Input);
assign(Output, 'output.txt');
rewrite(Output);

readln(n, m);
if n>m then max:=n else max:=m;
for i:=1 to n do for i1:=1 to m do
        begin
        read(c);
        if c=0 then map[i][i1]:=false;
        if c=1 then map[i][i1]:=true;
        end;
for i:=1 to max do
        begin
        for i1:=1 to n+1-i do for i2:=1 to m+1-i do
                begin
                if clear(i, i1, i2)=true then resp:=resp+1;
                end;
        end;
write(resp);
end.