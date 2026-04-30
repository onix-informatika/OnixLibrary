type oxCallback = procedure();

type
    TLocalNotifyEvent = class(TObject)
    public
        Callback: oxCallback;
        procedure NotifyEvent(Sender: TObject);
        constructor Create(Callback: oxCallback);
    end;

constructor TLocalNotifyEvent.Create(Callback: oxCallback);
begin
    self.Callback := Callback;
end;

procedure TLocalNotifyEvent.NotifyEvent(Sender: TObject);
begin
    self.Callback();
end;