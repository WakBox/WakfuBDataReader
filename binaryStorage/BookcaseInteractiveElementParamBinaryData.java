package com.ankamagames.wakfu.client.binaryStorage;

public class BookcaseInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected byte edG;
    
    public BookcaseInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public byte aNP()
    {
        int i = this.edG;
        return (byte)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.edG = (byte)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.get();
        this.edG = (byte)i;
    }
    
    final public int gZ()
    {
        return aPw.eFq.getId();
    }
}