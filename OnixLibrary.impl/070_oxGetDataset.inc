function oxGetDataset(dataset: String): TdlDataSet;
var c: TComponent;
begin
    c := AresFindComponent(dataset, OwnerForm);
    if c is TcxGridDBTableView then
    begin
        Result := TdlDataSet(TcxGridDBTableView(c).DataController.DataSet);
    end
    else if c is TcxDBLookupComboBox then
    begin
        Result := TdlDataSet(TcxDBLookupComboBox(c).DataBinding.DataSource.DataSet);
        _macro.eventlogadd('Upit za DataSet od Lookupa ili od krajnjeg DataSeta za ' + dataset + '? Rezultat je DataSet od krajnjeg DataSeta.');
    end
    else if c is TDaDBLookupComboBox then
    begin
        Result := TdlDataSet(TDaDBLookupComboBox(c).DataBinding.DataSource.DataSet);
        _macro.eventlogadd('Upit za DataSet od Lookupa ili od krajnjeg DataSeta za ' + dataset + '? Rezultat je DataSet od krajnjeg DataSeta.');
    end 
    else if c is TdlDataSet then
    begin
        Result := TdlDataSet(c);
    end 
    else if c is TcxGridDBBandedTableView then
    begin
        Result := TdlDataSet(TcxGridDBBandedTableView(c).DataController.DataSet); 
    end
    else if c is TNavigator3 then
    begin
        Result := TdlDataSet(TNavigator3(c).DataSource.DataSet);
    end else
    begin
        showmessage(dataset + ' nije TDataSet!');
    end;    
end;    




