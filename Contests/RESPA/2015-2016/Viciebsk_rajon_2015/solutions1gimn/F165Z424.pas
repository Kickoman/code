program a4;
var n, m, i, i1, max, maxn:integer;
med:real;
sity, sorted, sortnum:array[1..100000] of integer;

function near(st:real):integer;
var i:integer;
dist:real;
begin
dist:=sorted[m];
for i:=1 to m do
        begin
        //writeln(sity[i], ' ', st, ' ', abs(sity[i]-st));
        if abs(sity[i]-st)<dist then begin dist:=abs(sity[i]-st); near:=i; end;
        end;
end;

begin
assign(Input, 'input.txt');
reset(Input);
assign(Output, 'output.txt');
rewrite(Output);

readln(n, m);
for i:=1 to m do read(sity[i]);
for i:=m downto 1 do
        begin
        for i1:=1 to m do
                if sity[i1]>max then begin max:=sity[i1]; maxn:=i1; end;
        sorted[i]:=max;
        sortnum[i]:=maxn;
        sity[maxn]:=-sity[maxn];
        max:=0;
        end;
for i:=1 to m do sity[i]:=-sity[i];
med:=sorted[m]/n;
for i:=1 to n do
        begin
        write(near(i*med), ' ');
        end;
//writeln(med);
end.