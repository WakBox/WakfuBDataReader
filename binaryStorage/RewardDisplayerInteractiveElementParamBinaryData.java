package com.ankamagames.wakfu.client.binaryStorage;

public class RewardDisplayerInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int[] bCL;
    
    public RewardDisplayerInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int[] Ki()
    {
        return this.bCL;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bCL = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.bCL = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eFh.getId();
    }
}