function oxGetTempPath(): String;
var shell: TcShell;
begin
    shell := TcShell.Create();
    
    result := shell.GetTempPath();
end;




