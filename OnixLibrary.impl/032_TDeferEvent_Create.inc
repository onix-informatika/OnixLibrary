constructor TDeferEvent.Create(forCallback: oxCallback; forTimeout: Integer);
begin
    callback := forCallback;
    timeout := forTimeout;
    timer := TTimer.Create(nil);
    timer.Enabled := false;
    timer.OnTimer := TimerFired;
    timer.Interval := timeout;
    timer.Enabled := true;
end;




