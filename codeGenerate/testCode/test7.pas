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
        a := a-1;
end;

function FunctionName: Integer;
begin

end;

begin
	i := 0;
        goto 0000;
	9999:Main(i,i);
	i := 0;
	if (a = 0) then
    begin
     goto 0000;
	end
    goto 9999;


        for i:= 1 to 100 do
        begin
               i := 0;
        end;
        for i:= 100 downto 1 do
        begin
                i := 0;
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
        case i of
                0: i := i - 1;
                2: i := i - 1;
        end;
		write(i);
end.
