function oxSQLStepResultAnotherAres( stepId: Integer; aresAcKey: String = nil): String;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, aresAcKey);
    result := oxSQLExp(stepSQL);
end;




