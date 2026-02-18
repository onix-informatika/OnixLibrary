function oxGetDatasetSQL(dataSet: String): String;
var c: TComponent;
    strings: TStrings;
    ds: TdlDataSet;
begin
    c := AresFindComponent(dataSet, OwnerForm);
    if c is TdlDataSet then
    begin    
        ds := TdlDataSet(c); 
        if ds.DataSource <> nil then
        begin          
            strings := TdlDataSource(ds.DataSource).SQL;
            if strings <> nil then
            begin
                Result := strings.Text;
            end;
        end else 
        begin
            showmessage('DataSet je ispravna komponenta, ali trenutno ne postoji DataSource, pomakni upit SQL-a na kasniji korak u programu.');
        end;
    end else if c is TdlDataSource then
    begin
        strings := TdlDataSource(c).SQL;
        if strings <> nil then
        begin
            Result := strings.Text;
        end;
    end else 
    begin
        showmessage('dataset +  ne postoji kao dataset niti kao datasource!');
    end; 
end;

// dataset moze biti naziv dataseta, ali i grida, bilo cega sto je ovdje implementirano if else if...'



