package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldBuildingCatalogBinaryData implements dEZ {
    protected int az;
    protected int cpG;
    protected int exV;
    protected int exW;
    protected boolean exX;
    protected short exY;
    protected boolean exZ;
    protected int eya;
    protected cBk[] eyb;
    
    public HavenWorldBuildingCatalogBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int getOrder()
    {
        return this.cpG;
    }
    
    public int aZa()
    {
        return this.exV;
    }
    
    public int aZb()
    {
        return this.exW;
    }
    
    public boolean aZc()
    {
        return this.exX;
    }
    
    public short aZd()
    {
        int i = this.exY;
        return (short)i;
    }
    
    public boolean aZe()
    {
        return this.exZ;
    }
    
    public int aZf()
    {
        return this.eya;
    }
    
    public cBk[] aZg()
    {
        return this.eyb;
    }
    
    public void reset()
    {
        this.az = 0;
        this.cpG = 0;
        this.exV = 0;
        this.exW = 0;
        this.exX = false;
        this.exY = (short)0;
        this.exZ = false;
        this.eya = 0;
        this.eyb = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.cpG = a.getInt();
        this.exV = a.getInt();
        this.exW = a.getInt();
        this.exX = a.readBoolean();
        int i = a.getShort();
        this.exY = (short)i;
        this.exZ = a.readBoolean();
        this.eya = a.getInt();
        int i0 = a.getInt();
        this.eyb = new cBk[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.eyb[i1] = new cBk();
            this.eyb[i1].a(a);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFp.getId();
    }
}