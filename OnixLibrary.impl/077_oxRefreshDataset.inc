procedure oxRefreshDataset(dataset: String);
begin
    with oxGetDataset(dataset) do
    begin         
        Refresh;
        _macro.eventlogadd(dataset + ' refreshed');
    end;
end;




