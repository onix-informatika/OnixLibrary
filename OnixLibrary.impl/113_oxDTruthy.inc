function oxDTruthy(v: TDateTime): boolean;
begin
    Result := false;
    
    if v <> null then
    begin
        if v <> 0 then
        begin              
            Result := true;
        end;
    end;
end;




