package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldBuildingEvolutionBinaryData implements dEZ {
    protected int az;
    protected short hvt;
    protected int hvu;
    protected int hvv;
    protected long fES;
    protected byte bEk;
    
    public HavenWorldBuildingEvolutionBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short cfA()
    {
        int i = this.hvt;
        return (short)i;
    }
    
    public int cfB()
    {
        return this.hvu;
    }
    
    public int cfC()
    {
        return this.hvv;
    }
    
    public long getDelay()
    {
        return this.fES;
    }
    
    public byte Lb()
    {
        int i = this.bEk;
        return (byte)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.hvt = (short)0;
        this.hvu = 0;
        this.hvv = 0;
        this.fES = 0L;
        this.bEk = (byte)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.hvt = (short)i;
        this.hvu = a.getInt();
        this.hvv = a.getInt();
        this.fES = a.getLong();
        int i0 = a.get();
        this.bEk = (byte)i0;
    }
    
    final public int gZ()
    {
        return aPw.eFo.getId();
    }
}