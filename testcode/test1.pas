program ProgramName;
const
	a = 10;
type
        int=Integer;
        long=Integer;
        gao=record
            g : Integer;
        end;
var
	i,variableName: int;
	x,y,z:real;
procedure Main(a:Integer;var b: Integer);
begin
        writeln(a);
end;

function FunctionName: Integer;
begin

end;

begin
        goto 0000;
	9999:Main(a,a);
	i := a - 1;
        
	if (a = 0) then
        begin goto 0000;
        end;
        
	goto 9999;

        for i:= 1 to 100 do
        begin
                write(i);
        end;
        
        for i:= 100 downto 1 do
        begin
                writeln(i);
        end;
        
        i := 1;
        while(i < 100) do
        begin
                i := i + 1;
        end;
        
        repeat
         i := i - 1;
        until i = 0;

        if (i = 0) then
        begin
                i := i + 1;
        end
        else
        begin
                i := i - 1;
        end;


        if (i = 1) then 
        begin
                i := i - 1;
        end;

        goto 9999;
        0000:
        read(i);
        case i of
                0:writeln('a');
                2:writeln('b');
        end;
        readln;
end.
