function oxSQLExp(sql:string):string
var dataSet: TdlDataSet;
var firstFieldName: string;
begin
    dataSet := TdlDataSet.Create(Ares);
    dataSet.SQL.Text := sql;
    dataSet.Debug := true;
    dataSet.DontHandleException := true;
    try
        dataSet.Open;
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
                end;
            end;
        finally
            dataSet.Close;
        end;
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




