procedure oxBeforeButtonClick(button: String; callback: oxCallback);
var localBeforeClick: TLocalAfterClick;
begin
    with oxGetButton(button) do
    begin
        localBeforeClick := TLocalAfterClick.Create(OnClick);
        localBeforeClick.Callback := callback;
        localBeforeClick.AfterOldEvent := false;    
        OnClick := localBeforeClick.NewEvent;
        _macro.eventlogadd('New event set before, for ' + button);
    end;
end;




