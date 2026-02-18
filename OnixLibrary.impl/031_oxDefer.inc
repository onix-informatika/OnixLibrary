procedure oxDefer(callback: oxCallback; forMs: integer = 1);
var deferrer: TDeferEvent;
begin
    deferrer := TDeferEvent.Create(callback, forMs);
end;




