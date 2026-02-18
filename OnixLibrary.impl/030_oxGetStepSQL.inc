function oxGetStepSQL(stepId: Integer): String;
begin
    Result := oxGetStepSQLFromAres(stepId, Ares.AcKey);
end;




