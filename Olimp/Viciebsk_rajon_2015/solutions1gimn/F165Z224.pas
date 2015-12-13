program a2;
var n, m, i, i1:integer;
msgin, msgrl:array[1..1000000] of char;
begin
assign(Input, 'input.txt');
reset(Input);
assign(Output, 'output.txt');
rewrite(Output);

readln(n, m);
for i:=1 to n*m do
        begin
        read(msgin[i]);
        end;
for i:=0 to n-1 do
        begin
        for i1:=0 to m-1 do
                write(msgin[i+1+i1*n]);
        end;
end.
