type oxCallback = procedure();

type
    TLocalAfterClick = class(TObject)
    private                        
        oldEvent: TNotifyEvent;
    public                   
        AfterOldEvent: boolean;
        Callback: oxCallback;
        NewEvent: procedure(Sender: TObject);
        constructor Create(oldEvent: TNotifyEvent);
    end;

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

constructor TLocalAfterClick.Create(oldEvent: TNotifyEvent);
begin
    self.oldEvent := oldEvent;
end;

procedure TLocalAfterClick.NewEvent(Sender: TObject);
begin
     if self.AfterOldEvent then
     begin
        if assigned(self.oldevent) then self.oldEvent(Sender);
        self.callback;
     end else 
     begin      
        self.callback;
        if assigned(self.oldevent) then self.oldEvent(Sender);
     end;
end;