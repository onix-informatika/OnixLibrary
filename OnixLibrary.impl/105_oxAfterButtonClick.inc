procedure oxAfterButtonClick(button: String; callback: oxCallback);
var localAfterClick: TLocalAfterClick;
begin
    with oxGetButton(button) do
    begin
        localAfterClick := TLocalAfterClick.Create(OnClick);
        localAfterClick.Callback := callback;
        localAfterClick.AfterOldEvent := true;    
        OnClick := localAfterClick.NewEvent;
        _macro.eventlogadd('New event set after, for ' + button);
    end;
end;




