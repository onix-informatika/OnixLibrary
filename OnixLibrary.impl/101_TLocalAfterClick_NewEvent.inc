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




