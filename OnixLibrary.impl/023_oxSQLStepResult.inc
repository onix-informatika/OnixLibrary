function oxSQLStepResult( stepId: Integer): String;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, Ares.AcKey);
    result := oxSQLExp(stepSQL);
end;




