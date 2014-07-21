package com.ankamagames.wakfu.client.binaryStorage;

public class ChaosParamBinaryData implements dEZ {
    protected byte ivR;
    protected int ijU;
    
    public ChaosParamBinaryData()
    {
        super();
    }
    
    public byte cza()
    {
        int i = this.ivR;
        return (byte)i;
    }
    
    public int cvu()
    {
        return this.ijU;
    }
    
    public void reset()
    {
        this.ivR = (byte)0;
        this.ijU = 0;
    }
    
    public void a(ceb a)
    {
        int i = a.get();
        this.ivR = (byte)i;
        this.ijU = a.getInt();
    }
    
    final public int gZ()
    {
        throw new UnsupportedOperationException();
    }
}