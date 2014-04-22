package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldBoardInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int UA;
    protected short fxA;
    protected short fxB;
    protected short fxC;
    protected short fxD;
    
    public HavenWorldBoardInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public short btY()
    {
        int i = this.fxA;
        return (short)i;
    }
    
    public short btZ()
    {
        int i = this.fxB;
        return (short)i;
    }
    
    public short bua()
    {
        int i = this.fxC;
        return (short)i;
    }
    
    public short bub()
    {
        int i = this.fxD;
        return (short)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.UA = 0;
        this.fxA = (short)0;
        this.fxB = (short)0;
        this.fxC = (short)0;
        this.fxD = (short)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.UA = a.getInt();
        int i = a.getShort();
        this.fxA = (short)i;
        int i0 = a.getShort();
        this.fxB = (short)i0;
        int i1 = a.getShort();
        this.fxC = (short)i1;
        int i2 = a.getShort();
        this.fxD = (short)i2;
    }
    
    final public int gZ()
    {
        return aPw.eFw.getId();
    }
}