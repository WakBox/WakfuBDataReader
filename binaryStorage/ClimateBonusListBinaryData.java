package com.ankamagames.wakfu.client.binaryStorage;

public class ClimateBonusListBinaryData implements dEZ {
    protected int dwI;
    protected int[] hTR;
    
    public ClimateBonusListBinaryData()
    {
        super();
    }
    
    public int aAa()
    {
        return this.dwI;
    }
    
    public int[] cpH()
    {
        return this.hTR;
    }
    
    public void reset()
    {
        this.dwI = 0;
        this.hTR = null;
    }
    
    public void a(ceb a)
    {
        this.dwI = a.getInt();
        this.hTR = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eDK.getId();
    }
}