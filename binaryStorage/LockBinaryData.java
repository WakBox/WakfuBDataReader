package com.ankamagames.wakfu.client.binaryStorage;

public class LockBinaryData implements dEZ {
    protected int az;
    protected int ciw;
    protected int aWX;
    protected long cix;
    protected java.sql.Timestamp ciy;
    protected boolean ciz;
    
    public LockBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int YT()
    {
        return this.ciw;
    }
    
    public int uq()
    {
        return this.aWX;
    }
    
    public long YU()
    {
        return this.cix;
    }
    
    public java.sql.Timestamp YV()
    {
        return this.ciy;
    }
    
    public boolean YW()
    {
        return this.ciz;
    }
    
    public void reset()
    {
        this.az = 0;
        this.ciw = 0;
        this.aWX = 0;
        this.cix = 0L;
        this.ciy = null;
        this.ciz = false;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.ciw = a.getInt();
        this.aWX = a.getInt();
        this.cix = a.getLong();
        this.ciy = new java.sql.Timestamp(a.getLong());
        this.ciz = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eFF.getId();
    }
}