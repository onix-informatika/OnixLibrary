function oxSQLExpWithParams(sql: string; params: array of Variant): string;
var v: Variant;
    i: Integer;
    dataSet: TdlDataSet;
    firstFieldName: string;
    pName: string;
    strVal: string;
begin
    dataSet := oxSQLExpRowWithParams(sql, params);     
    try
        _macro.eventlogadd('izvodim ' + sql); 
        if (dataSet.LastError <> null) and (not dataSet.LastError.Contains('return rows')) then
        begin            
            _macro.eventlogadd('dataSet.LastError: ' + dataSet.LastError);
            raise Exception(dataSet.LastError);
        end; 
        if dataSet.EOF then begin
            Result := '';       
        end else begin                          
            if dataSet.Fields.Count > 0 then
            begin
                firstFieldName := dataSet.Fields[0].FieldName;
                Result := dataSet.FieldByName(firstFieldName).AsString;
            end else begin
                _macro.EventLogAdd('No return fields to return');
                Result := '';
            end;
        end;
    finally
        dataSet.Close;
    end;
end;




