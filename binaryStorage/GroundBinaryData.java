package com.ankamagames.wakfu.client.binaryStorage;

public class GroundBinaryData implements dEZ {
    protected int az;
    protected iC VD;
    protected akd VE;
    
    public GroundBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public iC hC()
    {
        return this.VD;
    }
    
    public akd hD()
    {
        return this.VE;
    }
    
    public void reset()
    {
        this.az = 0;
        this.VD = null;
        this.VE = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.VD = new iC(i);
        int i0 = 0;
        while(i0 < i)
        {
            int i1 = a.getInt();
            int i2 = a.getShort();
            this.VD.a(i1, (short)i2);
            i0 = i0 + 1;
        }
        int i3 = a.getInt();
        this.VE = new akd(i3);
        int i4 = 0;
        while(i4 < i3)
        {
            int i5 = a.getShort();
            int i6 = a.getShort();
            this.VE.m((short)i5, (short)i6);
            i4 = i4 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDV.getId();
    }
}