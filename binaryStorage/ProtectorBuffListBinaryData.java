package com.ankamagames.wakfu.client.binaryStorage;

public class ProtectorBuffListBinaryData implements dEZ {
    protected int dwI;
    protected int[] iFp;
    
    public ProtectorBuffListBinaryData()
    {
        super();
    }
    
    public int aAa()
    {
        return this.dwI;
    }
    
    public int[] cCe()
    {
        return this.iFp;
    }
    
    public void reset()
    {
        this.dwI = 0;
        this.iFp = null;
    }
    
    public void a(ceb a)
    {
        this.dwI = a.getInt();
        this.iFp = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eEt.getId();
    }
}