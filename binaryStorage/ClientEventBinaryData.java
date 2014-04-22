package com.ankamagames.wakfu.client.binaryStorage;

public class ClientEventBinaryData implements dEZ {
    protected int az;
    protected int aNz;
    protected short aVw;
    protected short aVx;
    protected String Uz;
    protected String[] aVy;
    protected boolean aVz;
    protected SM[] aVA;
    
    public ClientEventBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int getType()
    {
        return this.aNz;
    }
    
    public short tf()
    {
        int i = this.aVw;
        return (short)i;
    }
    
    public short tg()
    {
        int i = this.aVx;
        return (short)i;
    }
    
    public String gW()
    {
        return this.Uz;
    }
    
    public String[] th()
    {
        return this.aVy;
    }
    
    public boolean ti()
    {
        return this.aVz;
    }
    
    public SM[] tj()
    {
        return this.aVA;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aNz = 0;
        this.aVw = (short)0;
        this.aVx = (short)0;
        this.Uz = null;
        this.aVy = null;
        this.aVz = false;
        this.aVA = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aNz = a.getInt();
        int i = a.getShort();
        this.aVw = (short)i;
        int i0 = a.getShort();
        this.aVx = (short)i0;
        this.Uz = a.clg().intern();
        this.aVy = a.cll();
        this.aVz = a.readBoolean();
        int i1 = a.getInt();
        this.aVA = new SM[i1];
        int i2 = 0;
        while(i2 < i1)
        {
            this.aVA[i2] = new SM();
            this.aVA[i2].a(a);
            i2 = i2 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDH.getId();
    }
}