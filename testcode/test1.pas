program ProgramName;
const
	a: Integer = 10;
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

function FunctionName(): Integer;
begin

end;

begin
        goto 0000;
	9999:Main(a,a);
	i := a - 1;
	if (a = 0) then goto 0000;
	goto 9999;


        for i:= 1 to 100 do
                write(i);
        for i:= 100 downto 1 do
                writeln(i);

        i := 1;
        while(i < 100) do
                i := i + 1;

        repeat
         i := i - 1;
        until i = 0;

        if (i = 0) then
                i := i + 1
        else
                i := i - 1;


        if (i = 1) then i := i - 1;

        goto 9999;
        0000:
        read(i);
        case i of
                0..1:writeln('a');
                2..3:writeln('b');
                else writeln('c');
        end;
        readln;
end.
