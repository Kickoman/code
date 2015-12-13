var a:array[1..1005,1..1005]of string;i,j,N,M,ns,f:longint;s:string;
Begin
  assign(input,'Input.txt');
  assign(output,'Output.txt');
  reset(input);
  rewrite(output);
  readln(N,M);
  readln(s);
  ns:=length(s);
  for j:=1 to M do
    for i:=1 to N do
     begin 
      a[i,j]:=s[1];
      Delete(s,1,1);
     end;
  for i:=1 to N do
    for j:=1 to M do write(a[i,j]);
  close(input);
  close(output);  
    
End.