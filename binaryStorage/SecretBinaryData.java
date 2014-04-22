package com.ankamagames.wakfu.client.binaryStorage;

public class SecretBinaryData implements dEZ {
    protected int az;
    protected short bjI;
    protected short bjJ;
    
    public SecretBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short oD()
    {
        int i = this.bjI;
        return (short)i;
    }
    
    public short BI()
    {
        int i = this.bjJ;
        return (short)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bjI = (short)0;
        this.bjJ = (short)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.bjI = (short)i;
        int i0 = a.getShort();
        this.bjJ = (short)i0;
    }
    
    final public int gZ()
    {
        return aPw.eFS.getId();
    }
}