module bit3(updown,CLKP,QA,QB,QC);

input updown,CLKP;
output QA,QB,QC;

wire wQA,wQA_not,wQB,wQB_not,wQC,wQC_not,wnotupdow,wauq,wand3,wor1,wand2,wor2,wand4;
ex1 FFA(wQA,wQA_not, 1, CLKP, 1);
ex1 FFB(wQB,wQB_not, wor1, CLKP,wor1);
ex1 FFC(wQC,wQC_not, wor2, CLKP,wor2);

not not_updown(wnotupdow,updown);
and and_updown_qa(wauq, updown, wQA);
and and2(wand2,not_updown,wQA_not);
or or1(wor1,wand2,wQA);
and and3(wand3, wand2,wQB_not);
and and4(wand4, wauq, wQB);
or or2(wor2,wand4,wand3);

endmodule