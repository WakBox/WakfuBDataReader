package com.ankamagames.wakfu.client.binaryStorage;

public class MagiCraftLootListBinaryData implements dEZ {
    protected int az;
    protected byte iiz;
    protected wb[] iiA;
    
    public MagiCraftLootListBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public byte cuF()
    {
        int i = this.iiz;
        return (byte)i;
    }
    
    public wb[] cuG()
    {
        return this.iiA;
    }
    
    public void reset()
    {
        this.az = 0;
        this.iiz = (byte)0;
        this.iiA = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.get();
        this.iiz = (byte)i;
        int i0 = a.getInt();
        this.iiA = new wb[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.iiA[i1] = new wb();
            this.iiA[i1].a(a);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFI.getId();
    }
}