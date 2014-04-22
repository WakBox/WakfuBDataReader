package com.ankamagames.wakfu.client.binaryStorage;

public class ProtectorBuffBinaryData implements dEZ {
    protected int cAA;
    protected int aZE;
    protected String aZr;
    protected byte mFq;
    protected int[] ceW;
    
    public ProtectorBuffBinaryData()
    {
        super();
    }
    
    public int afp()
    {
        return this.cAA;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public String vS()
    {
        return this.aZr;
    }
    
    public byte dxH()
    {
        int i = this.mFq;
        return (byte)i;
    }
    
    public int[] dxI()
    {
        return this.ceW;
    }
    
    public void reset()
    {
        this.cAA = 0;
        this.aZE = 0;
        this.aZr = null;
        this.mFq = (byte)0;
        this.ceW = null;
    }
    
    public void a(ceb a)
    {
        this.cAA = a.getInt();
        this.aZE = a.getInt();
        this.aZr = a.clg().intern();
        int i = a.get();
        this.mFq = (byte)i;
        this.ceW = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eEs.getId();
    }
}