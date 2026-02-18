function oxSQLExpRowWithBlob(sql: String; blob: TStream; params: array of Variant): TdlDataSet;
var dataSet: TdlDataSet;
begin
    dataSet := oxMakeDSWithParams(sql, params);
    
    dataSet.ParamByName('blob').LoadFromStream(blob, ftBlob); 
         
    try
        dataSet.Open;
        Result := dataSet;
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




