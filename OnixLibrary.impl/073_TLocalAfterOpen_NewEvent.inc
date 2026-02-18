procedure TLocalAfterOpen.NewEvent(DataSet: TdlDataSet);
begin
     if self.AfterOldEvent then
     begin
        if assigned(self.oldevent) then self.oldEvent(DataSet);
        self.callback;
     end else 
     begin      
        self.callback;
        if assigned(self.oldevent) then self.oldEvent(DataSet);
     end;
end;




