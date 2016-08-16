var N,i,sum,p,k:longint;a:array[1..1000010]of longint;
Begin
   assign(input,'Input.txt');
   assign(output,'Output.txt');
   reset(input);
   rewrite(output);
   readln(N);
   for i:=1 to N do read(a[i]);
   
   sum:=0;
   for i:=1 to N do 
     sum:=sum+a[i];
   k:=0;  
   if sum mod N=0 then 
     begin
       p:=sum div N;
       for i:=1 to N do 
         if a[i]<p then k:=k+p-a[i];
       writeln('YES');
       write(k);
     end
   else 
     begin
       while sum mod N<>0 do 
        begin 
         k:=k+1;
         sum:=sum+1;
        end;
       writeln('NO');
       write(k);
     End;
 close(input);
 close(output);
End.