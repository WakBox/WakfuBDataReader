package com.ankamagames.wakfu.client.binaryStorage;

public class GemBackgroundInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int bCI;
    protected int[] cWx;
    
    public GemBackgroundInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int Kh()
    {
        return this.bCI;
    }
    
    public int[] anl()
    {
        return this.cWx;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bCI = 0;
        this.cWx = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.bCI = a.getInt();
        this.cWx = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eDT.getId();
    }
}