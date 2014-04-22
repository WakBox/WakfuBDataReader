package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldDefinitionBinaryData implements dEZ {
    protected int az;
    protected short aC;
    protected byte dPI;
    protected short dPJ;
    protected short dPK;
    protected short dPL;
    protected short dPM;
    
    public HavenWorldDefinitionBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short D()
    {
        int i = this.aC;
        return (short)i;
    }
    
    public byte aIi()
    {
        int i = this.dPI;
        return (byte)i;
    }
    
    public short aIj()
    {
        int i = this.dPJ;
        return (short)i;
    }
    
    public short aIk()
    {
        int i = this.dPK;
        return (short)i;
    }
    
    public short aIl()
    {
        int i = this.dPL;
        return (short)i;
    }
    
    public short aIm()
    {
        int i = this.dPM;
        return (short)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aC = (short)0;
        this.dPI = (byte)0;
        this.dPJ = (short)0;
        this.dPK = (short)0;
        this.dPL = (short)0;
        this.dPM = (short)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.aC = (short)i;
        int i0 = a.get();
        this.dPI = (byte)i0;
        int i1 = a.getShort();
        this.dPJ = (short)i1;
        int i2 = a.getShort();
        this.dPK = (short)i2;
        int i3 = a.getShort();
        this.dPL = (short)i3;
        int i4 = a.getShort();
        this.dPM = (short)i4;
    }
    
    final public int gZ()
    {
        return aPw.eFl.getId();
    }
}