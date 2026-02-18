procedure oxAfterDataSetOpen(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
var localAfterOpen: TLocalAfterOpen;
begin
    with oxGetDataset(dataset) do
    begin
        localAfterOpen := TLocalAfterOpen.Create(AfterOpen);
        localAfterOpen.Callback := callback;
        localAfterOpen.AfterOldEvent := afterOldEvent;    
        AfterOpen := localAfterOpen.NewEvent;
        _macro.eventlogadd('New event set for ' + dataset);
    end;
end;




