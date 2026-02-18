procedure oxBeforeDataSetOpen(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
var localAfterOpen: TLocalAfterOpen;
begin
    with oxGetDataset(dataset) do
    begin
        localAfterOpen := TLocalAfterOpen.Create(BeforeOpen);
        localAfterOpen.Callback := callback;
        localAfterOpen.AfterOldEvent := afterOldEvent;    
        BeforeOpen := localAfterOpen.NewEvent;
        _macro.eventlogadd('New event set for ' + dataset);
    end;
end;




