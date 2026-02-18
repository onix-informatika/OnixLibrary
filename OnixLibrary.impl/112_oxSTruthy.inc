function oxSTruthy(v: String; zeroIsFalsy: boolean = false): boolean;
begin
    Result := false;
    
    if v <> null then
    begin
        if TRIM(v) <> '' then
        begin              
            if (not zeroIsFalsy) or 
               (zeroIsFalsy and (TRIM(v) <> '0')) then
            begin
                Result := true;
            end;
        end;
    end;
end;




