function oxMakeDSWithParams(sql: String; params: array of Variant): TdlDataSet;
var i: Integer;
    pName: string;
begin        
    Result := TdlDataSet.Create(Ares);
    Result.SQL.Text := sql;
    Result.Debug := true;
    Result.DontHandleException := true;
    
    for i := 0 to Length(params) - 1 do
    begin                           
        pname := 'p' + inttostr(i);
        _macro.EventLogAdd('type of param value: ' + IntToStr(VarType(params[i])));
        if VarType(params[i]) = 8209 then
        begin    
            raise Exception.Create('Are you using oxSQLStoreBlob for blobs?');               
        end;
                    
        Result.Params.ParamByName(pname).Value := params[i];
    end; 
end;




