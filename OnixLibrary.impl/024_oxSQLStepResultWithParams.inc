function oxSQLStepResultWithParams(stepId: Integer; params: array of Variant): String;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, Ares.AcKey);
    result := oxSQLExpWithParams(stepSQL, params);
end;




