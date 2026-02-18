procedure TDeferEvent.TimerFired(Sender: TObject);
begin
    timer.Enabled := false;
    callback();
end;




