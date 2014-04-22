package com.ankamagames.wakfu.client.binaryStorage;

public class DecorationInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int[] cWx;
    
    public DecorationInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int[] anl()
    {
        return this.cWx;
    }
    
    public void reset()
    {
        this.az = 0;
        this.cWx = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.cWx = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eDO.getId();
    }
}