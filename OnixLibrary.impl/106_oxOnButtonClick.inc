procedure oxOnButtonClick(button: String; callback: oxCallback);
var localEvent: TLocalNotifyEvent;
begin
    with oxGetButton(button) do
    begin
        localEvent := TLocalNotifyEvent.Create(callback);
        localEvent.Callback := callback;
        OnClick := localEvent.NotifyEvent;
        _macro.eventlogadd('New event set for ' + button);
    end;
end;




