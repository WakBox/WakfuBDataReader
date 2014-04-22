package com.ankamagames.wakfu.client.binaryStorage;

public class InteractiveElementModelBinaryData implements dEZ {
    protected int az;
    protected short eqi;
    protected int baO;
    protected int dKc;
    protected byte iP;
    protected int ddd;
    protected int edU;
    
    public InteractiveElementModelBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short getType()
    {
        int i = this.eqi;
        return (short)i;
    }
    
    public int ant()
    {
        return this.baO;
    }
    
    public int aFz()
    {
        return this.dKc;
    }
    
    public byte ci()
    {
        int i = this.iP;
        return (byte)i;
    }
    
    public int arj()
    {
        return this.ddd;
    }
    
    public int aVd()
    {
        return this.edU;
    }
    
    public void reset()
    {
        this.az = 0;
        this.eqi = (short)0;
        this.baO = 0;
        this.dKc = 0;
        this.iP = (byte)0;
        this.ddd = 0;
        this.edU = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.eqi = (short)i;
        this.baO = a.getInt();
        this.dKc = a.getInt();
        int i0 = a.get();
        this.iP = (byte)i0;
        this.ddd = a.getInt();
        this.edU = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eDX.getId();
    }
}