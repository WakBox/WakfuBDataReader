package com.ankamagames.wakfu.client.binaryStorage;

public class KrosmozGameCollectionInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected byte fxs;
    
    public KrosmozGameCollectionInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public byte btS()
    {
        int i = this.fxs;
        return (byte)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.fxs = (byte)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.get();
        this.fxs = (byte)i;
    }
    
    final public int gZ()
    {
        return aPw.eFu.getId();
    }
}