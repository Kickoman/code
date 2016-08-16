program a1;
var n, i, sum, repl, count :integer;
a:array[1..1000000] of integer;
begin
assign(Input, 'input.txt');
reset(Input);
assign(Output, 'output.txt');
rewrite(Output);

sum:=0;
readln(n);
for i:=1 to n do
        begin
        read(a[i]);
        sum:=sum+a[i];
        end;
if sum mod n = 0 then
        begin
        writeln('YES');
        count:=sum div n;
        for i:=1 to n do
                begin
                if a[i]<count then repl:=repl+count-a[i];
                end;
        write (repl);
        end
else
        begin
        writeln('NO');
        write ((sum div n + 1)*n-sum);
        end;
end.
