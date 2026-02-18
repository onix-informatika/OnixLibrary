function oxSQLExpRowWithParams(sql: string; params: array of Variant): TdlDataSet;
var firstFieldName: string;
begin
    Result := oxMakeDSWithParams(sql, params);
             
    try
        Result.Open;
    except on E:Exception do
        begin 
            if not E.message.Contains('return rows') then 
            begin
                _macro.EventLogAdd('Thrown exception: ' + E.message);
                raise E;
            end; 
        end;
    end;
end;




